package com.company;

import java.awt.*;
import java.util.ArrayList;

public class Run {

    ArrayList<Firework> fireworks;

    public Run(){
        fireworks = new ArrayList<Firework>();
    }

    public void render(Graphics g){

        if((int)(Random.random(0,20)) == 1){
            fireworks.add(new Firework5());
        }

        for(int i = 0 ; i < fireworks.size();i++){
            fireworks.get(i).update();
            fireworks.get(i).show(g);
            if(fireworks.get(i).isDeath()){
                fireworks.remove(i);
            }
        }
    }

  /*  public static Firework getRandomFirework(){

        int randomNum = (int)(Math.random() * 10);
        switch (randomNum){
            case 0:{
                return new Firework0();
            }
            case 1:{
                return new Firework1();
            }
            case 2:{
                return new Firework2();
            }
            case 3:{
            }
                return new Firework3();
            }
            case 4:{
                return new Firework4();
            case 5:{
                return new Firework5();
            }
            case 6:{
                return new Firework6();
            }
            case 7:{
                return new Firework7();
            }
            case 8:{
                return new Firework8();
            }
        }
        return null;
    }
    */
}
