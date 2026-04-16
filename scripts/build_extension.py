from setuptools import Extension

def build(setup_kwargs):
    setup_kwargs.update(
        {
            "ext_modules": [
                Extension(
                    "asyncinotify_zos.libzosinotify",
                    sources=[
                        "src/zos_inotify_exports.c",
                        "src/zos_inotify_impl.c",
                    ],
                )
            ]
        }
    )
