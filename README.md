# 300Tang [WIP]

300Tang is a simple app that periodically shows you random [Tang poetry](https://en.wikipedia.org/wiki/Tang_poetry). I wrote this GNOME extension with C and [GTK+](https://developer.gnome.org/gtk3/stable/gtk-getting-started.html) for myself to display a different poem periodically on my desktop. I used [this resource](https://www.mandarinchineseschool.com/index.php/resources/104-free-download-300-tang-poems-in-chinese-pinyin-and-english) to download the e-book as pdf, and then extracted plain text from them. 

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
* Add actual extension files like metadata
* Reformat the code with GNU style indentation
* Add random poem selection
* Add option to save and/or copy to clipboard
* Add poems
* Add Pinyin and English 

# License
MIT.

