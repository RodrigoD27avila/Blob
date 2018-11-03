FILE=$(zenity --file-selection)
gnome-terminal -e "vim \"$FILE\""
