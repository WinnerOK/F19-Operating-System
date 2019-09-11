gcc ex1.c -o ex1

max=10
for i in `seq  $max`
do
	echo "execition # $i"
	./ex1
done
