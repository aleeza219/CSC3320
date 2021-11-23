#Aleeza Iftikhar
#Email: aiftikhar2@student.gsu.edu
#This program display contacts, search contact, add contact, edit contact, delete contact, and exit functions on phonebook.
phone_file="phone.txt"
menu()
{
echo "Welcome to Phone Book!"
echo "----------------------"
echo "ENTER 1 to Show contacts list"
echo "ENTER 2 to Search contact"
echo "ENTER 3 to Add contact"
echo "ENTER 4 to Edit contact"
echo "ENTER 5 to Delete contact"
echo "ENTER 6 to Exit phonebook"
}



touch "$phone_file"
chmod 600 "$phone_file"

clear

while [ "$option" != "6" ]
do
	firstname=""
	lastname=""
	phone=""
	address=""
	
	oldfirstname=""
	oldlastname=""
	oldphone=""
	oldaddress=""
	
	newfirstname=""
	newlastname=""
	newphone=""
	newaddress=""
	
	case "$option" in
	1)
		if [ -s "$phone_file" ];then
			echo
			echo "Sorted on Last Name"
			echo
			
			sort -t":" -k2 "$phone_file" | column -s: -t | more
		else
			echo
			echo "Phone directory '$phone_file' not found"
		fi
		
		menu
		
		read option
		continue
		;;
	2)
		if [ ! -r "$phone_file" ];then
			echo
			echo "Sorry You are not allowed to read '$phone_file'"
			echo
			
			exit 1
		fi
		
		echo
		
		while [ -z "$firstname" ]
		do
			echo -n "Enter First Name: "
			read firstname
			
			if [ "$firstname" = "exit" ];then
				exit 0
			fi
		done
		
		while [ -z "$lastname" ]
		do
			echo -n "Enter Last Name: "
			read lastname
			
			if [ "$lastname" = "exit" ];then
				exit 0
			fi
		done
		
		firstname=$(echo "$firstname" | tr -s ' ')
		lastname=$(echo "$lastname" | tr -s ' ')
		
		echo
		entry=$(grep -iw "$firstname:$lastname" "$phone_file")
		
		if [ -z "$entry" ];then
			echo "sorry, no entry found"
			
			menu
			
			read option
			continue
		else
			echo "$entry"
		fi
		
		menu
		
		read option
		continue
		;;
	3)
		if [ ! -w "$phone_file" ];then
			menu
			echo "Sorry, You are not allowed to write into $phone_file"
			echo
			
			exit 1
		fi
		echo
		
		while [ -z "$firstname" ]
		do
			echo -n "Enter First Name: "
			read firstname
			
			if [ "$firstname" = "exit" ];then
				exit 0
			fi
		done
			
			while [ -z "$lastname" ]
		do
			echo -n "Enter Last Name: "
			read lastname
			
			if [ "$lastname" = "exit" ];then
				exit 0
			fi
		done
		
		while [ -z "$phone" ]
		do
			echo -n "Enter phone#"
			read phone
			
			if [ "$phone" = "exit" ];then
				exit 0
			fi
		done
		
		while [ -z "$address" ]
		do
			echo -n "Enter address"
			read address
			
			if [ "$address" = "exit" ];then
				exit 0
			fi
		done
		
		echo "$firstname:$lastname:$phone:$address" >> "$phone_file"
		echo
		echo "Info: New phone added"
		
		menu
		
		read option
		continue
		;;
		
	4)
		if [ ! -w "$phone_file" ];then
			menu
			echo "Sorry, You are not allowed to write into $phone_file"
			echo
			
			exit 1
		fi
		echo
		
		while [ -z "$oldfirstname" ]
		do
			echo -n "Enter old First Name"
			read oldfirstname
			
			if [ "$oldfirstname" = "exit" ];then
				exit 0
			fi
		done
			
			while [ -z "$oldlastname" ]
		do
			echo -n "Enter Old Last Name"
			read oldlastname
			
			if [ "$oldlastname" = "exit" ];then
				exit 0
			fi
		done
		
		while [ -z "$newfirstname" ]
		do
			echo -n "Enter new First Name"
			read newfirstname
			
			if [ "$newfirstname" = "exit" ];then
				exit 0
			fi
		done
			
			while [ -z "$newlastname" ]
		do
			echo -n "Enter new Last Name"
			read newlastname
			
			if [ "$newlastname" = "exit" ];then
				exit 0
			fi
		done
		
		while [ -z "$newphone" ]
		do
			echo -n "Enter new phone#"
			read newphone
			
			if [ "$newphone" = "exit" ];then
				exit 0
			fi
		done
			
			while [ -z "$newaddress" ]
		do
			echo -n "Enter new address"
			read newaddress
			
			if [ "$newaddress" = "exit" ];then
				exit 0
			fi
		done
		
		oldfirstname=$(echo "oldfirstname" | tr -s ' ')
		oldlastname=$(echo "oldlastname" | tr -s ' ')
		
		echo
		oldrecord=$(grep -iw "$oldfirstname:$oldlastname" "$phone_file")
		newrecord="$newfirstname:$newlastname:$newphone:$newaddress"
		
		if [ -z "$oldrecord" ];then
			echo "sorry, no entry found"
			
			menu
			
			read option
			continue
		else
			sed -i "s/$oldrecord/$newrecord/" "$phone_file"
			echo "contact is modified"
		fi
		
		menu
		echo -n "Enter option [1-6]]: "
		read option
		continue
		;;
		
	5)echo
		while [ -z "$firstname" ]
		do
			echo -n "Enter First Name: "
			read firstname
			
			if [ "$firstname" = "exit" ];then
				exit 0
			fi
		done
		
		while [ -z "$lastname" ]
		do
			echo -n "Enter Last Name: "
			read lastname
			
			if [ "$lastname" = "exit" ];then
				exit 0
			fi
		done
		
		firstname=$(echo "$firstname" | tr -s ' ')
		lastname=$(echo "$lastname" | tr -s ' ')
		
		tmpfile=$(mktmp)
		grep -iwv "$firstname:$lastname" "$phone_file" > "$tmmpfile"
		
		origrowcount=$(wc -l < "$phone_file")
		tmprowcount=$(wc -l < "$tmpfile")
		
		if [ "$origrowcount" -eq "$tmprowcount" ];then
			echo
			echo "sorry, no entry found"
			
			meenu
			
			read option
			continue
		else
			mv "$tmpfile" "$phone_file"
			echo
			echo "Info: Deleted phone"
			
			menu
			
			read option
			
			continue
		fi
		;;
	6) echo
		exit 0
		;;
		*) menu
		
		read option
	esac
done
echo
exit
