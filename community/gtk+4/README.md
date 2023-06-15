# gtk4

## Installation

In order to install gtk+4, you are going to have to rebuild freetype-harfbuzz
to have support for harfbuzz-glib.

Run the following series of commands:

`$ kiss fork freetype-harfbuzz`

`$ cd freetype-harfbuzz; sed -i '/Dglib/s/disabled/enabled/' build`

`$ KISS_PROMPT=1 kiss b; KISS_PROMPT=1 kiss i`

Now you can build gtk+4.
