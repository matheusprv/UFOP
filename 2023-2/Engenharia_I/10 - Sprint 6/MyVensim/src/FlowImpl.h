
#ifndef FLOWIMPL_H
#define FLOWIMPL_H

#include "Flow.h"
#include "handleBodySemDebug.h"

/**
* @brief   Definition of class Flow, which represents a conection between two systems.
*/
class FlowImpl : public Body{
protected:
    /** @brief Name of the Flow */
    string name;
    /** @brief Pointer to source System */
    System* source;
    /** @brief Pointer to target System */
    System* target;

public:
    /**
     * @brief   Default constructor for Flow.
    */
    FlowImpl();

    /**
     * @brief   Constructor for the Flow class with parameters.
     * @param   name Name of the flow.
     * @param   source Pointer to the source system.
     * @param   target Pointer to the target system.
    */
    FlowImpl(const string& name, System* source, System* target);

    /**
     * @brief   Constructor for the Flow class with a name.
     * @param   name Name of the flow.
    */
    FlowImpl(const string& name);

    /**
     * @brief   Constructor for the Flow class with source and target systems.
     * @param   source  Pointer to the source system.
     * @param   target  Pointer to the target system.
    */
    FlowImpl(System* source, System* target);

    /**
     * @brief   Copy constructor for the Flow class.
     * @param   flow  Flow object to be copied.
    */
    FlowImpl(Flow& flow);

    /**
     * @brief   Virtual destructor for the Flow class.
    */
    virtual ~FlowImpl();

    /**
     * @brief   Get the source system of the flow.
     * @return  Pointer to the source system.
    */
    System* getSource() const;
    
    /**
     * @brief   Set the source system of the flow.
     * @param   source   Pointer to the source system.
    */
    void setSource(System * source);

    /**
     * @brief   Get the target system of the flow.
     * @return  Pointer to the target system.
    */
    System* getTarget() const;
    
    /**
     * @brief   Set the target system of the flow.
     * @param   target Pointer to the target system.
    */
    void setTarget(System * target);

    /**
     * @brief   Get the name of the flow.
     * @return  Name of the flow.
    */
    string getName() const;

    /**
     * @brief  Set the name of the flow.
     * @param  name Name of the flow.
     * @return No return value.
    */
    void setName(const string name);


    /**
     * @brief   Overload of operator equals to copy a Flow.
     * @param   flow Object to be copied.
     * @return  Reference to the copied Flow.
    */
    FlowImpl& operator=(const FlowImpl& flow);

    /**
     * @brief   Overload of operator == to compare two Flow
     * @param   flow Object to be compared.
     * @return  True if they are equals. False otherwise
    */
   bool operator==(const Flow& flow) const;

    /**
     * @brief   Pure virtual function to execute the flow equation.
     * @return  Result of the equation.
    */
    virtual double executeEquation() = 0;

};

template <typename T>
class FlowHandle : public Flow, public Handle<T>{
public:
    FlowHandle(){
        Handle<T>::pImpl_->setName("");
        Handle<T>::pImpl_->setSource(NULL);
        Handle<T>::pImpl_->setTarget(NULL);
    }
    FlowHandle(const string& name, System* source, System* target){
        Handle<T>::pImpl_->setName(name);
        Handle<T>::pImpl_->setSource(source);
        Handle<T>::pImpl_->setTarget(target);
    }
    FlowHandle(System* source, System* target){
        Handle<T>::pImpl_->setName("");
        Handle<T>::pImpl_->setSource(source);
        Handle<T>::pImpl_->setTarget(target);
    }
    FlowHandle(const string& name){
        Handle<T>::pImpl_->setName(name);
        Handle<T>::pImpl_->setSource(NULL);
        Handle<T>::pImpl_->setTarget(NULL);
    }
    FlowHandle(Flow &flow){
        Handle<T>::pImpl_->setName(flow.getName());
        Handle<T>::pImpl_->setSource(flow.getSource());
        Handle<T>::pImpl_->setTarget(flow.getTarget());
    }

    virtual ~FlowHandle(){}

    System* getSource() const{return Handle<T>::pImpl_->getSource();}
    void setSource(System * source){Handle<T>::pImpl_->setSource(source);}

    System* getTarget() const{return Handle<T>::pImpl_->getTarget();}
    void setTarget(System * target){Handle<T>::pImpl_->setTarget(target);}
    
    string getName() const{return Handle<T>::pImpl_->getName();}
    void setName(const string name){Handle<T>::pImpl_->setName(name);}

    double executeEquation(){return Handle<T>::pImpl_->executeEquation();}
};



#endif
