package com.company;

public class Firework4 extends Firework {

    @Override
    public void update() {
        super.update();
        if(!isExplore && this.particle.getVel().y >= 0){
            isExplore = true;
            double r = 0;
            int randomnumber = (int)(Math.random()*4);
            if(randomnumber == 0){
                r = 0.1;
            }
            else if (randomnumber == 1) {
                r = 0.4;
            }
            else if (randomnumber ==2 ){
                r = 0.15;
            }
            else{
                r = 0.2;
            }
            int t = (int)(Random.random(2,100));
            for(double i = 0 ; i < Random.PI()*2;i += 0.08) {
                Vector2 pos = new Vector2(this.particle.getPos().x,this.particle.getPos().y);
                double x = r*16*Math.pow(Math.sin(i),3);
                double y = -r *(13*Math.cos(i) - 5*Math.cos(2*i) - 2*Math.cos(3*i) - Math.cos(4*i));
                Vector2 vel = new Vector2(x,y);
                Particle newParticle = new Particle(pos,vel,this.particle.getColor());
                newParticle.setLife(150);
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
