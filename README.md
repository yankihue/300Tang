# 300Tang [WIP]

300Tang is a simple app that periodically shows you random [Tang poetry](https://en.wikipedia.org/wiki/Tang_poetry). I wrote this GNOME extension with C and [GTK+](https://developer.gnome.org/gtk3/stable/gtk-getting-started.html) for myself to display a different poem periodically on my desktop. I used [this resource](https://github.com/xuchunyang/300) to download the 320 poems in json format.


![Screenshot](/screenshot1.png)

If you don't interact with the window, a new poem will be displayed after a while. You can choose to save it for later, or copy it to your clipboard. 

https://developer.gnome.org/

# Installation
You need to have [GTK+](https://www.gtk.org).

To compile the source code, use
```bash
gcc 300Tang.c `pkg-config --cflags --libs gtk+-3.0` -o 300Tang
```
and then run it with
```bash
./300Tang

```
(incomplete)

# TODO
* Add actual extension files like metadata and package with flatpak
* Reformat the code with GNU style indentation
* Add random poem selection
* Add option to save and/or copy to clipboard
* Add Pinyin and English (need to find machine-readable source for this)

# License
MIT.

