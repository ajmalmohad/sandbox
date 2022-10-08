echo "Enter a Number: "
read num
res=1

for (( c = "$num"; c>=1; c-- ))
do
res=$((c*res))
done
echo "$res"