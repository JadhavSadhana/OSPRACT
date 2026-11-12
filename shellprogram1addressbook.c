
#!/bin/bash

file="address.txt"

while true
do
    echo "1.Create 2.View 3.Insert"
    echo "4.Delete 5.Modify 6.Exit"
    read -p "Enter choice: " ch

    case $ch in
    1)
        touch "$file"
        echo "Address book created"
        ;;
    2)
        cat "$file"
        ;;
    3)
        read -p "Enter Name: " name
        read -p "Enter Phone: " phone
        echo "$name $phone" >> "$file"
        ;;
    4)
        read -p "Enter name to delete: " name
        grep -v "^$name " "$file" > temp
        mv temp "$file"
        ;;
    5)
        read -p "Enter name to modify: " name
        grep -v "^$name " "$file" > temp
        read -p "New name: " n
        read -p "New phone: " p
        echo "$n $p" >> temp
        mv temp "$file"
        ;;
    6)
        exit
        ;;
    *)
        echo "Invalid choice"
        ;;
    esac
done
TO EXECUTE nano address.sh
THEN RUN chmod +x address.sh
./address.sh