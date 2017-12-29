project('teensy-freertos-blink',
    version : '1.0',
    default_options : [
        'buildtype=minsize',
        'b_staticpic=false',
    ])

assert(meson.is_cross_build(), 'Teensy projects can only be built in a cross build environment.')

objcopy = find_program(meson.get_cross_property('objcopy'))
teensy_loader_cli = find_program('/opt/teensy_loader_cli/teensy_loader_cli')

teensy_core_sp = subproject('teensy-core')
teensy_core_dep = teensy_core_sp.get_variable('teensy_core_dep')

teensy_mcu = meson.get_cross_property('teensy_mcu')
freeRTOS = get_option('teensy-core:freertos')

teensy_ldscript = teensy_core_sp.get_variable('teensy_ldscript')
local_ldflags = [
        '-T' + join_paths(meson.source_root(), 'subprojects', 'teensy-core', teensy_ldscript)
    ]

src = [
        'src/main.cpp'
    ]

exe = executable('blink', src,
        dependencies : [teensy_core_dep],
        link_args : local_ldflags
    )

hex = custom_target('blink.hex',
        input : exe,
        output : 'blink.hex',
        command : [objcopy, '-O', 'ihex', '-R', '.eeprom',
            '@INPUT@', '@OUTPUT@'],
    )

run_target('flash',
        command : [teensy_loader_cli, '--mcu=' + teensy_mcu, '-v', '-w', hex],
        depends : exe
    )
