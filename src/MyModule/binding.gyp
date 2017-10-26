{
    "targets": [
        {
            "target_name": "mymoduleND",
            'cflags!': ['-fno-exceptions'],
            'cflags_cc!': ['-fno-exceptions'],
            'conditions': [
                ['OS=="mac"', {
                    'xcode_settings': {
                        'GCC_ENABLE_CPP_EXCEPTIONS': 'YES'
                    }
                }]
            ],
            "sources": ["mymodulejs.cc",
                        "mymodule.cc"],
            "include_dirs": [
                "<!(node -e \"require('nan')\")",
                "./",
                "/usr/local/include/",
                "/usr/local/include/eigen3"
            ]
        },
        {
        "target_name": "action_after_build",
      "type": "none",
      "dependencies": [ "mymoduleND" ],
      "copies": [
        {
          "files": [ "<(PRODUCT_DIR)/mymoduleND.node" ],
          "destination": "../main/"
        }
      ]
    }
    ]
}
