`./squeez $1 > temp.intermediate1`
`./normalize temp.intermediate1 > temp.intermediate2`
`./reduction temp.intermediate2 > temp.intermediate3`
`./stemming temp.intermediate3 > $2`
`rm temp.intermediate1 temp.intermediate2 temp.intermediate3`
