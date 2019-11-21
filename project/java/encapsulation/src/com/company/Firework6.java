package com.company;

import java.awt.*;

public class Firework6 extends Firework {
    private Firework2 f1;
    private Firework2 f2;

    @Override
    public void update() {
        super.update();

        if(!isExplore && this.particle.getVel().y >= 0){
            isExplore = true;
            Vector2 pos1 = new Vector2(this.particle.getPos().x,this.particle.getPos().y);
            Vector2 pos2 = new Vector2(this.particle.getPos().x,this.particle.getPos().y);
            Vector2 velLeft = new Vector2(-1,0);
            Vector2 velRight = new Vector2(1,0);
            f1 = new Firework2(pos1,velLeft,this.particle.getColor());
            //f2 = new Firework2(pos2,velRight,this.particle.getColor());
            f1.particle.setRadius(6);
            //f2.particle.setRadius(6);
            f1.particle.setLife(200);
            //f2.particle.setLife(200);
        }
        if(isExplore){
            f1.update();
            //f2.update();
            f1.particle.apply_force(new Vector2(-0.1,0));
            //f2.particle.apply_force(new Vector2(0.1,0));
        }
    }

    @Override
    public void show(Graphics g) {
        if(!isExplore){
            this.particle.show(g);
        }else{
            //f2.show(g);
            f1.show(g);
        }
    }
}
