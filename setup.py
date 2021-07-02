from setuptools import setup
import os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), "Embedded Pixel_Image_Steganography_1_.ipynb"))
setup(name='Embedded Acceleration',
      version='0.1',
      description='pynq-jupyter',
      url='https://mygit.th-deg.de/vt16684/embedded-acceleration.git',
      author='vipin and Majd',
      author_email='vipin.thomas@stud.th-deg.de',
      license='MIT',
      packages=[],
      install_requires=['bs4==0.0.1',
                        'requests==2.25.1',
                         'panda==0.3.1',
                         'plotly==5.1.0',
                         'matplotlib',
                         'pillow',
                         'numpy'],
      zip_safe=False)
