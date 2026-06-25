from setuptools import setup, Extension

# Define the extension module
calculator_module = Extension(
    'calculator',        # The name of the module as it will appear in Python
    sources=['mathutils.c'] # The C source file
)

# Run the setup
setup(
    name='CalculatorPackage',
    version='1.0',
    description='This is a simple C extension for basic arithmetic',
    ext_modules=[calculator_module]
)
