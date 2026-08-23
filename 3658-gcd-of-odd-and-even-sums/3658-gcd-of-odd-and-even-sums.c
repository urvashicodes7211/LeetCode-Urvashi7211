int gcdOfOddEvenSums(int n) {
    int sumo = 0,sume = 0;
    for(int i=1;i<2*n;i++){
        if(i%2 == 0){
            sume += i;
        }else{
            sumo += i;
        }
    }
    while(sumo != 0) {
        int r = sume % sumo;
        sume = sumo;
        sumo = r;
    }

    return sume;
}