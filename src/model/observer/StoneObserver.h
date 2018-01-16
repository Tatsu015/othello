#ifndef STONEOBSERVER_H
#define STONEOBSERVER_H


class StoneItem;

class StoneObserver
{
public:
    StoneObserver();
    virtual ~StoneObserver();

    virtual void update();
    void setStoneItem(StoneItem* stoneItem);

private:
    StoneItem* m_stoneItem = nullptr;
};

#endif // STONEOBSERVER_H
