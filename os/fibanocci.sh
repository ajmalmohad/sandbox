echo "Enter Number of Terms :"
read num
first=1
second=1

echo -n "The Sequence is : "
if (( "$num" < 1 ))
then
echo "Nothing"
elif (( "$num" == 1 ))
then
echo "$first"
else
echo -n "$first "
echo -n "$second "
num=$((num-2))
while [ "$num" -gt 0 ]
do
third=$((first+second))
echo -n "$third "
first=$((second))
second=$((third))
num=$((num-1))
done
echo " "
fi