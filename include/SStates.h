#ifndef SSTATES_H
#define SSTATES_H

//This class warps the states of the shadow functionality.
class SStates
{
    public:
        //The default constructor
        SStates();

        //To set the shadow system on
        void setOn(bool on);

        //To set the shadow "initialized" state to true
        void setInitialized();

        //To get the "on" state
        bool isOn() const;

        //To get the "initialized" state
        bool isInitialized() const;

    private:
        //The states
        bool m_on, m_initialized;
};

#endif // SSTATES_H
