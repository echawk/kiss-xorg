# shiboken2-pyside2

## Installation

In order to build this package, you need to build qt5 with accessibility
support, otherwise the build will fail. If there is a fix found, this
readme will be updated accordingly.

To build 'qt5' with accessibility, run the following commands:

`$ kiss fork qt5; cd qt5; sed -i '/access/d' build; kiss build`

