for((i=1;;i++)); do
	echo $i
	./gen $i > in
	./a < in > out
	x=$(./c < out) 
	if [[ "$x" == "no" ]]; then  
        break
    fi

done
