package com.company;

public class Firework1 extends Firework {

    @Override
    public void update() {
        super.update();
        if(!isExplore && this.particle.getVel().y >= 0){
            isExplore = true;
            int totalsParticle = (int)(Random.random(50,200));
            Vector2 randomRadius = new Vector2((int)(Random.random(1,5)),(int)(Random.random(1,5)));
            for(int i = 0 ; i < totalsParticle;i++) {
                Vector2 pos = new Vector2(this.particle.getPos().x,this.particle.getPos().y);
                Vector2 vel = Random.random2D();
                vel.mult(randomRadius);
                Particle newParticle = new Particle(pos,vel,this.particle.getColor());
                this.theParticles.add(newParticle);
            }
        }
        if(isExplore){
            for(int i = 0 ; i < this.theParticles.size();i++){
                this.theParticles.get(i).update();
                //this.theParticles.get(i).apply_force(new Vector2(0,0.05));
                this.theParticles.get(i).reduceVel();
                if(this.theParticles.get(i).getLife() < 0){
                    this.theParticles.remove(i);
                }
            }
        }
    }
}