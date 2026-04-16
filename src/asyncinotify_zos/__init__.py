import ctypes
import glob
import os
import sys


_here = os.path.dirname(__file__)
matches = glob.glob(os.path.join(_here, "libzosinotify*.so"))

if sys.platform != 'zos':
    raise NotImplementedError("asyncinotify_zos only works on z/OS")
elif not matches:
    raise ImportError("libzosinotify shared library not found")

ctypes.CDLL(matches[0], mode=ctypes.RTLD_GLOBAL)
