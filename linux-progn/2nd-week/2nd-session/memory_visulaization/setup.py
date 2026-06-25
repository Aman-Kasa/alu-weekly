from setuptools import setup, Extension

# Define the C extension module
ram_module = Extension('ram_monitor', sources=['ram_monitor.c'])

setup(
    name='RamMonitor',
    version='1.0',
    description='C extension for reading RAM usage',
    ext_modules=[ram_module]
)
