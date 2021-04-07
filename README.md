# 300Tang

300Tang is a simple app that periodically shows you random [Tang poetry](https://en.wikipedia.org/wiki/Tang_poetry). I wrote this GNOME extension with C for myself to display a different poem periodically on my desktop. I used [this resource](https://www.mandarinchineseschool.com/index.php/resources/104-free-download-300-tang-poems-in-chinese-pinyin-and-english) to download the e-book as pdf, and then extracted plain text from them. 

![Screenshot](/screenshot1.png)


If you don't interact with the window, a new poem will be displayed after a while. You can choose to save it for later, or copy it to your clipboard. 
For more info on GNOME software and extensions you can check out https://developer.gnome.org/. 

# Installation
To compile the source code, use
```bash
gcc 300Tang.c `pkg-config --cflags --libs gtk+-3.0` -o 300Tang
```
and then run it with
```bash
./300Tang

```
You can then change your startup application settings to have it start automatically next time.

# License
MIT. For more information check the LICENSE file.

