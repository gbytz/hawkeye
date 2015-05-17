#ifndef AKGAMEOBJECT_H
#define AKGAMEOBJECT_H


class AKGameObject
{
    public:
        static unsigned int COUNT;

        AKGameObject();
        virtual ~AKGameObject();

        unsigned int id;
        int x;
        int y;
        int width;
        int height;

    protected:
    private:

};

#endif // AKGAMEOBJECT_H
