from setuptools import setup, Extension
import sys

if sys.platform != "zos":
    raise RuntimeError("asyncinotify-zos can only be built on z/OS")

ext = Extension(
    "libzosinotify",
    sources=["zos_inotify_impl.c",
             "zos_inotify_exports.c",
             ])

setup(name="asyncinotify-zos",
      ext_modules=[ext],
      )
