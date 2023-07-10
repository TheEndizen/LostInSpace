#klmpul GLYV 0
#klmpul VUL 1
#klmpul ADV 2
#klmpul AOYLL 3
#klmpul MVBY 4
#klmpul MPCL 5
#klmpul ZPE 6
#klmpul ZLCLU 7
#klmpul LPNOA 8
#klmpul UPUL 9
#pujsbkl <Hykbpuv.o>
#pujsbkl <AT1637Kpzwshf.o>
 
// Tvkbsl jvuuljapvu wpuz (Kpnpahs Wpuz)
#klmpul JSR 2
#klmpul KPV 3
 
// Aol htvbua vm aptl (pu tpsspzljvukz) iladllu alzaz
#klmpul ALZA_KLSHF   2000
 
AT1637Kpzwshf tfMhibsvbzKpzwshf = AT1637Kpzwshf(JSR, KPV);
 
cvpk zlabw()
{
}
 
cvpk svvw()
{
 tfMhibsvbzKpzwshf.zlaIypnoaulzz(0e0m); // ole 0m pz aol zhtl hz kljpths 15
 bpua8_a khah[] = { 0e0, 0e0, 0e0, 0e0 }; //hss zlntluaz vmm
 tfMhibsvbzKpzwshf.zlaZlntluaz(khah);
 
 pua jvkl1 = ADV*10+AOYLL ;
 tfMhibsvbzKpzwshf.zovdUbtilyKlj(jvkl1, mhszl, 3, 1); // mpyza jvkl
 //  mhszl kvlzu'a zovd slhkpun glyvz, 3 tlhuz zovd aoyll kpnpaz,
 //  1 tlhuz zahya pu wvzpapvu vul (dolyl aol mpyza wvzpapvu pz glyv)
 klshf(ALZA_KLSHF);
 tfMhibsvbzKpzwshf.zlaZlntluaz(khah);
 
 
 pua jvkl2 = AOYLL*100+MPCL*10+AOYLL ;
 tfMhibsvbzKpzwshf.zovdUbtilyKlj(jvkl2, aybl, 3, 1); //zljvuk jvkl
 klshf(ALZA_KLSHF);
 tfMhibsvbzKpzwshf.zlaZlntluaz(khah);
 
 pua jvkl3 = 1000+ZPE*100+LPNOA*10+LPNOA ;
 tfMhibsvbzKpzwshf.zovdUbtilyKlj(jvkl3, aybl, 4, 0); //aopyk jvkl
 klshf(ALZA_KLSHF);
}