export PROG=./program

export VAR=1
echo "\n---------------------------------------\nTesting: $VAR\n-------------------------------------------"
$PROG $VAR

export VAR=0
echo "\n---------------------------------------\nTesting: $VAR\n-------------------------------------------"
$PROG $VAR

export VAR=1.
echo "\n---------------------------------------\nTesting: $VAR\n-------------------------------------------"
$PROG $VAR

export VAR=1.f
echo "\n---------------------------------------\nTesting: $VAR\n-------------------------------------------"
$PROG $VAR

export VAR=0.f
echo "\n---------------------------------------\nTesting: $VAR\n-------------------------------------------"
$PROG $VAR

export VAR=.f
echo "\n---------------------------------------\nTesting: $VAR\n-------------------------------------------"
$PROG $VAR

export VAR=1.0.0f
echo "\n---------------------------------------\nTesting: $VAR\n-------------------------------------------"
$PROG $VAR

export VAR=1...0f
echo "\n---------------------------------------\nTesting: $VAR\n-------------------------------------------"
$PROG $VAR

export VAR=a
echo "\n---------------------------------------\nTesting: $VAR\n-------------------------------------------"
$PROG $VAR

export VAR=ab
echo "\n---------------------------------------\nTesting: $VAR\n-------------------------------------------"
$PROG $VAR

export VAR="a b"
echo "\n---------------------------------------\nTesting: $VAR\n-------------------------------------------"
$PROG $VAR

export VAR=2147483648
echo "\n---------------------------------------\nTesting: $VAR\n-------------------------------------------"
$PROG $VAR

export VAR=2147483648.0
echo "\n---------------------------------------\nTesting: $VAR\n-------------------------------------------"
$PROG $VAR

export VAR=2147483648.0f
echo "\n---------------------------------------\nTesting: $VAR\n-------------------------------------------"
$PROG $VAR

export VAR=333333333333333333333333333333333333333333333333333333333.0
echo "\n---------------------------------------\nTesting: $VAR\n-------------------------------------------"
$PROG $VAR

export VAR=333333333333333333333333333333333333333333333333333333333.0f
echo "\n---------------------------------------\nTesting: $VAR\n-------------------------------------------"
$PROG $VAR

export VAR=0.00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001f
echo "\n---------------------------------------\nTesting: $VAR\n-------------------------------------------"
$PROG $VAR
