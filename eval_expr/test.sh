#!/bin/bash
count=1
try() {
	program="./eval_expr"			#実行ファイルへのパス
	input="$1"

	actual=`eval "${program} \"${input}\""`
	expected=$((${input}))

	if [ "$actual" = "$expected" ]; then
		echo -e "\033[1;32mtest$count passed: \033[0;39m"
		echo -e "\033[0;34m	$input = $actual\033[0;39m"
	else
		echo -e "\033[1;31mtest$count failed: \033[0;39m"
		echo -e "\033[0;34m	$input = $expected expected, but got $actual\033[0;39m"
		exit 1
	fi
	echo
	let ++count
}

try "3 - 2"
try "1 + 2 * 4 % 2"
try "3 + 42 * (1 - 2 / (3 + 4) - 1 % 21) + 2"
try "42"
try "-42"
try "1+12"
try "3+42*(1-2/(3+4)-1%21)+1"
try "1 +2 *( - 1-1 *( 22+2*1)+1* ( - 1 + 1* 1))"
try "((((((((((0))))))))))"


echo OK
