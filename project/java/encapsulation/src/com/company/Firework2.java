package com.company;

import java.awt.*;

public class Firework2 extends Firework {
    private int life = 150;
    private boolean startFiring = false;
    private boolean fly = false;

    public Firework2(){}
    public Firework2(Vector2 pos, Vector2 vel, Color color){
        super();
        this.particle.setPos(pos);
        this.particle.setVel(vel);
        this.particle.setColor(color);
        fly = true;
        startFiring = true;
        isExplore = true;
    }

    @Override
    public void update() {
        if(!fly){
            super.update();
            if(!isExplore && this.particle.getVel().y >= 0){
                isExplore = true;
                startFiring = true;
            }
        }
        else{
            this.particle.update();
        }

        if(startFiring && life > 0){
            Vector2 pos = new Vector2(this.particle.getPos().x,this.particle.getPos().y);
            Vector2 vel = Random.random2D();
            Particle newParticle = new Particle(pos,vel,this.particle.getColor());
            newParticle.setLife(200);
            this.theParticles.add(newParticle);

            for(int i = 0 ; i < this.theParticles.size();i++){
                this.theParticles.get(i).update();
                this.theParticles.get(i).reduceVel();
                if(this.theParticles.get(i).getLife() < 0){
                    this.theParticles.remove(i);
                }
            }
            life--;
        }
        else{
            this.theParticles.removeAll(this.theParticles);
        }

    }
}
