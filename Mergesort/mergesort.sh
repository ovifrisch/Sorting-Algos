#!/bin/bash

function merge () {
    arrs=('arr1' 'arr2' 'res')
    idx=-1
    while (( $# > 0 )); do
        idx=$(expr $idx + 1)
        num_els=$1; shift
        curr_arr=()
        while (( $num_els > 0 )); do
            num_els=$(expr $num_els - 1)
            curr_arr+=($1); shift
        done
        if (( ${#curr_arr[@]} == 0 )); then
            eval "${arrs[idx]}=()"
        else
            eval "${arrs[idx]}=(${curr_arr[@]})"
        fi
    done

    if (( ${#arr1[@]} == 0 )); then
        res=(${res[@]} ${arr2[@]})
        echo ${res[@]}
        return 0
    elif (( ${#arr2[@]} == 0 )); then
        res=(${res[@]} ${arr1[@]})
        echo ${res[@]}
        return 0
    elif (( ${arr1[0]} < ${arr2[0]} )); then
        res+=(${arr1[0]})
        arr1=("${arr1[@]:1}")
    else
        res+=(${arr2[0]})
        arr2=("${arr2[@]:1}")
    fi

    res=($(merge ${#arr1[@]} ${arr1[@]} ${#arr2[@]} ${arr2[@]} ${#res[@]} ${res[@]}))
    echo ${res[@]}
}

function mergesort () {
    arr=()
    while [[ $# > 0 ]]; do
        arr+=($1); shift
    done

    if [[ ${#arr[@]} < 2 ]]; then
        echo ${arr[@]}
        return 0
    fi

    left=${arr[@]::$((${#arr[@]} / 2 ))}
    right=${arr[@]:$((${#arr[@]} / 2 ))}

    x=($(mergesort ${left[@]}))
    y=($(mergesort ${right[@]}))

    res=($(merge ${#x[@]} ${x[@]} ${#y[@]} ${y[@]} 0))
    echo ${res[@]}
}

if (( $# > 0  )); then
    res=$(mergesort $@)
    echo $res
else
    array=(4 1 2 45 -10)
    res=($(mergesort ${array[@]}))
    echo ${res[@]}
fi