
int normalizar(int value, int size){
    value %= size;
    if(value < 0)
        value += size;
    return value;
}

main(int argc, char const *argv[])
{
    int pos = 0;
    int dir = 0;
    int dist = 0;

    int pos_abs = pos + (dir == 1)? dist : -dist;
    //int pos_abs = pos + dir * dist;
/*     
    while(pos_abs > 12)
        pos_abs -= 12;
    while(pos_abs < 0)
        pos_abs += 12; 
*/
    print("%d\n", normalizar(pos_abs, 12));
    return 0;
}
