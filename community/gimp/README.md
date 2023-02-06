# gimp

## Installation

In order to install this package, you are going to have to do a bunch
of rebuilds of gtk software, with gobject/introspection/glib functionality.

Install 'gobject-introspection'

`$ kiss b gobject-introspection`

### freetype/harfbuzz

`$ kiss fork freetype-harfbuzz`

Then run:

`$ sed -i -E "s/(gobject=)disabled/\1enabled" build`

To enable gobject.

Then rebuild:

`$ kiss b`

### pango

`$ kiss fork pango`

Then run:

`$ sed -i -E "s/(introspection=)disabled/\1enabled" build`

To enable gobject-introspection.

Then rebuild:

`$ kiss b`

### atk

`$ kiss fork atk`

Then run:

`$ sed -i -E "s/(introspection=)false/\1true" build`

To enable gobject-introspection.

Then rebuild:

`$ kiss b`

### gdk-pixbuf

`$ kiss fork gdk-pixbuf`

Then:

`$ sed -i -E "s/(\. output)/-Dintrospection=enabled \1/" build`

Then rebuild:

`$ kiss b`

### gtk+3

First install librsvg:

`$ kiss b librsvg`

Then:

`$ kiss fork gtk+3`

You will need to run the following sed command:

`$ sed -i -E -e "s/^rm -f.*//" -e "s/(introspection=)no/\1yes/" build`

This will give you the 'gtk-encode-symbolic-svg' executable as well as enabling
gobject.

Then rebuild:

`$ kiss b`

### gegl

Just perform a rebuild:

`$ kiss b gegl`

### gexiv2

Just perform a rebuild:

`$ kiss b gexiv2`

This should cover all of the packages that you will have to fork & rebuild,
however if you run into build errors relating to missing '.gir' files,
try enabling the introspection/gobject option for said package.

