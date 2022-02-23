for f in *; do
  if [[ $f == *.in.txt ]]
  then
    echo "Creating ${f::-7}.out.txt"
    ./a.out < $f > ${f::-7}.out.txt
  fi
done

