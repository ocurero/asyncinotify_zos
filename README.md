asyncinotify wrapper for z/OS
=============================

[![Project Status: Active – The project has reached a stable, usable state and is being actively developed.](https://www.repostatus.org/badges/latest/active.svg)](https://www.repostatus.org/#active) [![builds.sr.ht status](https://builds.sr.ht/~ocurero/asyncinotify_zos/commits/main/.build.yml.svg)](https://builds.sr.ht/~ocurero/asyncinotify_zos/commits/main/.build.yml?) ![z/OS](https://img.shields.io/badge/works%20on-z/OS-8A2BE2)

Due to z/OS-specific DLL constraints, asyncinotify needs this tiny wrapper written in C.

* Open Source: GPL 3.0 or latter.
* Website: <https://sr.ht/~ocurero/asyncinotify_zos/>

Install
-------

A C compiler is required to install this package from source. See [this](https://www.ibm.com/docs/en/python-zos/3.14?topic=using-cc-compilers-open-enterprise-sdk-python-314) page for supported compilers and required environment variables to use them.

```
# Install from PyPI
pip3 install asyncinotify_zos
```

```
# Install from source
pip3 install asyncinotify_zos_<version>.tar.gz
```


Why is it needed?
-----------------

Python can load C functions from files in the Unix filesystem hierarchy. Unfortunately, on z/OS most functions are not located in Unix files but in MVS data sets. As of April 2026, Python is not able to load functions directly from MVS data sets.

There is an idea ([PY-I-14](https://ideas.ibm.com/ideas/PY-I-14)) already opened for IBM to implement an alternative loader so that Python can load functions from MVS data sets. Once this functionality is implemented, this wrapper will no longer be necessary. Note that this will also require modifications to asyncinotify upstream package.


Quickstart
----------

Using **asyncinotify** is very simple:

```python

from pathlib import Path
from asyncinotify import Inotify, Mask
import asyncio

async def main():
    # Context manager to close the inotify handle after use
    with Inotify() as inotify:
        # Adding the watch can also be done outside of the context manager.
        # __enter__ doesn't actually do anything except return self.
        # This returns an asyncinotify.inotify.Watch instance
        inotify.add_watch('/tmp', Mask.ACCESS | Mask.MODIFY | Mask.OPEN | Mask.CREATE | Mask.DELETE | Mask.ATTRIB | Mask.CLOSE | Mask.MOVE | Mask.ONLYDIR)
        # Iterate events forever, yielding them one at a time
        async for event in inotify:
            # Events have a helpful __repr__.  They also have a reference to
            # their Watch instance.
            print(event)

            # the contained path may or may not be valid UTF-8.  See the note
            # below
            print(repr(event.path))

asyncio.run(main())
```

This will asynchronously watch the /tmp directory and report events it encounters.
