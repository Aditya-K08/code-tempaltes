function array_sum() {
    typeset -a data=("$@")
    sum=0
    for x in "${data[@]}"
    do
        if [[ "$x" =~ ^[0-9]+$ ]]; then
            ((sum += x))
        fi
    done
    echo "$sum"
}