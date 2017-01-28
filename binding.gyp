{
    "variables": {
        "module_name": "winlock",
    },
    "targets": [
        {
            "target_name": "<(module_name)",
            "sources": [
                "src/main/c++/winlock.cpp",
                "src/main/c++/bindings.cpp"
            ],
            "defines": [
                "UNICODE"
            ],
            "include_dirs": [
                "<!(node -e \"require('nan')\")"
            ]
        },
        {
            "target_name": "move-to-target",
            "type": "none",
            "dependencies": [
                "<(module_name)"
            ],
            "copies": [
                {
                    "files": [ "<(PRODUCT_DIR)/<(module_name).node" ],
                    "destination": "target"
                }
            ]
        }
    ]
}