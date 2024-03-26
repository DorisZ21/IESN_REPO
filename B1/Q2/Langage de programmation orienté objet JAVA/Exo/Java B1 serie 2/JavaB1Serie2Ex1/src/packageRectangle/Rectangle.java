package packageRectangle;

public class Rectangle {
    private int coordoneeX;
    private int coordoneeY;
    private int largeur;
    private int hauteur;

    public Rectangle(int coordoneeX,int coordoneeY,int largeur,int hauteur){
        setCoordoneeX(coordoneeX);
        setCoordoneeY(coordoneeY);
        setLargeur(largeur);
        setHauteur(hauteur);
    }

    // Surcharge de constructeur
    public  Rectangle(int largeur,int hauteur){
        this(0,0,largeur,hauteur);
    }

    public int getCoordoneeX(){
        return this.coordoneeX;
    }

    public int getCoordoneeY(){
        return this.coordoneeY;
    }

    public int getLargeur(){
        return this.largeur;
    }

    public int getHauteur(){
        return this.hauteur;
    }

    public void setCoordoneeX(int coordoneeX){
        if(coordoneeX >= 0){
            this.coordoneeX = coordoneeX;
        }
    }

    public void setCoordoneeY(int coordoneeY){
        if(coordoneeY >= 0){
            this.coordoneeY = coordoneeY;
        }
    }

    public void setLargeur(int largeur){
        if (largeur >= 0){
            this.largeur = largeur;
        }
    }

    public void setHauteur(int hauteur){
        if (hauteur >= 0){
            this.hauteur = hauteur;
        }
    }

    public void deplacerEn(int x, int y){
        setCoordoneeX(this.coordoneeX + x);
        setCoordoneeY(this.coordoneeY + y);
    }

    public void modifierHauteur(int delta){
        setHauteur(this.hauteur + delta);
    }

    public void modifierLargeur(int delta){
        setLargeur(this.largeur + delta);
    }
}
