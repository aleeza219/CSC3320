#Aleeza Iftikhar
#Email: aiftikhar2@student.gsu.edu
#Program: Simple Calculator using regex
#Description: Performs addition, subtraction, multiplication, division, and modulation on integers.
#Other features: Stores result to be used in next calculation, clear function (resets stored values to zero), and cancel function (exit/turnoff calculator)

start_calc=true
calc_cont=true
num1=0
num2=0
result=0
operator=+
first_run=true
opert_entered=0
num1_entered=0
operator_regex="^(\+|\-|\*|%|\/)$" #regex variable
multi_op_regex="^(\*)$" #regex variable
num_regex="^[0-9]+$" #regex variable

while [ $start_calc=true ]; do
	while [ $calc_cont=true ]; do
		echo
		if [ $num1_entered -eq 1 ] && [ $opert_entered -eq 0 ];then
		echo "Enter operator(+,-,*,/,%) OR 'C' for Cancel OR 'CE' for clear: "
		elif [ $opert_entered -eq 1 ];then
		echo "Enter num OR 'C' for Cancel OR 'CE' for clear: "
		else
		echo "Enter num OR operator(+,-,*,/,%) OR 'C' for Cancel OR 'CE' for clear: "
		fi
		
		read user_entry
		
		
		echo
		if [[ $user_entry =~ $operator_regex ]] && [ $opert_entered -eq 0 ]; then
		operator=$user_entry
		opert_entered=1
		elif [[ $user_entry =~ $num_regex ]] && [ $opert_entered -eq 0 ] && [ $num1_entered -eq 0 ];then
		num1=$user_entry
		num1_entered=1
		elif [[ $user_entry =~ $num_regex ]] && [ $opert_entered -eq 1 ];then
		num2=$user_entry
		num1_entered=0
		break;
		elif [ $user_entry = C ]; then
		echo "-------Cancelling the calculator...bye--------"
		break 2;
		elif [ $user_entry = CE ]; then
		echo "clearing all the entries, everything set to Zero"
		num1=0
		num2=0
		opert_entered=0
		num1_entered=0
		else
		echo "---------------invalid entry-------------------"
		fi
		
	
	done
	
	
	echo "num1 = $num1 ; num2 = $num2 ; operator = $operator"
		
	if [[ $operator =~ $multi_op_regex ]];then
	result=`expr $num1 \* $num2`
	echo "operator changed $operator"
	else
	result=`expr $num1 $operator $num2`
	fi
	

		echo "result = $result"
		num1=$result
		opert_entered=0
done
