import glob
import os
import ctypes

_here = os.path.dirname(__file__)
matches = glob.glob(os.path.join(_here, "libzosinotify*.so"))

if not matches:
    raise ImportError("libzosinotify shared library not found")

ctypes.CDLL(matches[0], mode=ctypes.RTLD_GLOBAL)
