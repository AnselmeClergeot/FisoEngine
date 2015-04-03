#ifndef SSTATES_H
#define SSTATES_H


class SStates
{
    public:
        SStates();
        //To set on
        void setOn(bool on);

        //To set initialized
        void setInitialized();

        //To get initialized/on states
        bool isOn() const;
        bool isInitialized() const;
    private:
        //The states
        bool m_on, m_initialized;
};

#endif // SSTATES_H
