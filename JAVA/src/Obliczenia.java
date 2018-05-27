/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author gosiak
 */
public class Obliczenia {
    double Ra, La, b, J, ia, w , k1 , k2 , omega;
    double okres, amplituda;
    
    //1- prostokąt, 2- trójkąt, 3- sinus, 4- skok
    double Pobudzenie(int numer, double wartosc, double krok){
        switch (numer) {
            case 1:
                if(Math.sin(2*Math.PI*wartosc/okres)>0) return amplituda;
                else return -amplituda;
            case 2:
                if((Math.sin(2*Math.PI*wartosc/okres)>0) && (Math.cos(2*Math.PI*wartosc/okres)>0)){
                    while (wartosc > okres) wartosc -= okres;
                    return 4*amplituda*wartosc/okres;
                }
                else if((Math.sin(2*Math.PI*wartosc/okres)>0) && (Math.cos(2*Math.PI*wartosc/okres)<0)){
                    while (wartosc > okres) wartosc -= okres;
                    return -4*amplituda*wartosc/okres + 2*amplituda;
                }
                else if((Math.sin(2*Math.PI*wartosc/okres)<0) && (Math.cos(2*Math.PI*wartosc/okres)<0)){
                    while (wartosc > okres) wartosc -= okres;
                    return -4*amplituda*wartosc/okres + 2*amplituda;
                }
                else if((Math.sin(2*Math.PI*wartosc/okres)<0) && (Math.cos(2*Math.PI*wartosc/okres)>0)){
                    while (wartosc > okres) wartosc -= okres;
                    return 4*amplituda*wartosc/okres - 4*amplituda;
                }   break;
            case 3:
                return (amplituda*Math.sin(2*Math.PI*wartosc/okres));
            case 4:
                if (wartosc > 0.2) return amplituda;
                break;
            default:
                break;
        }
        return 0;    
}
    
   double euleria(double krok, double La, double pobudzenie, double Ra, double ia, double k2, double w){
       	double euler;
        euler = krok * (1/La)*(pobudzenie- Ra*ia - k2*w);
        return euler;
    }
 
   double euleromega(double krok, double J, double k1, double ia, double b, double omega){
       	double euler;
        euler = krok * (1/J)*(k1*ia - b*omega);
        return euler;
    }
   
   double eulerw(double krok, double omega){
       	double euler;
        euler = krok * omega;
        return euler;
    }
   



}
