for f in *; do
  if [[ $f == *.in.txt ]]; then
    echo -n Score ${f::1}': '
    cat ${f::-7}.out.txt > tmp
    echo >> tmp
    cat $f >> tmp
    ./score.out < tmp
  fi
done

