#ifndef MODEL_H
#define MODEL_H

#include "System.h"
#include "Flow.h"
#include <vector>

/**
* @brief   Definition of class Model, which represents the model to be executed.
*/
class Model{
protected:
public:

    //typedefs
    /**
     * @brief Defining a name for the system vector
    */
    typedef vector<System*> :: iterator systemsIterator;
    /**
     * @brief Defining a name for the flow vector
    */
    typedef vector<Flow*> :: iterator flowsIterator;

    
    /**
    * @brief   Virtual destructor for the Model class.
    */
    virtual ~Model() {};

    /**
    * @brief   Get the name of the model.
    * @return  Name of the model.
    */
    virtual string getName() const = 0;
    
    /**
    * @brief  Set the name of the model.
    * @param  name     Name of the model.
    * @return No return value.
    */
    virtual void setName(const string & name) = 0;

    /**
    * @brief Get the iterator pointing for the first item in the container.
    * @param No parameters.
    * @return Iterator pointing to the first item of the system container.
    */
    virtual systemsIterator systemBegin() = 0;
    /**
    * @brief Get the iterator pointing for the last item in the container.
    * @param No parameters.
    * @return Iterator pointing to the last item of the system container.
    */
    virtual systemsIterator systemEnd() = 0;

    /**
    * @brief Get the iterator pointing for the first item in the container.
    * @param No parameters.
    * @return Iterator pointing to the first item of the flows container.
    */
    virtual flowsIterator flowsBegin() = 0;
    /**
    * @brief Get the iterator pointing for the last item in the container.
    * @param No parameters.
    * @return Iterator pointing to the last item of the flows container.
    */
    virtual flowsIterator flowsEnd() = 0;

    /**
    * @brief Return the number of items in flows' container
    * @param No parameters.
    * @return int value representing the amount of itens in the container
    */
    virtual int flowsSize() = 0;
    /**
    * @brief Return the number of items in systems' container
    * @param No parameters.
    * @return int value representing the amount of itens in the container
    */
    virtual int systemsSize() = 0;


    /**
    * @brief  Add a flow to the model's container of flows.
    * @param  flow Pointer to the flow to be added.
    * @return True if the addition is successful, false otherwise.
    */
    virtual bool add(Flow * flow) = 0;
    /**
    * @brief  Add a system to the model's container of systems.
    * @param  flow Pointer to the flow to be added.
    * @return True if the addition is successful, false otherwise.
    */
    virtual bool add(System * system) = 0;

    /**
    * @brief  Remove a flow from the model's container of flows.
    * @param  flow Pointer to the flow to be removed.
    * @return True if the removal is successful, false otherwise.
    */
    virtual bool remove(Flow * flow) = 0;
    /**
    * @brief  Remove a system from the model's container of systems.
    * @param  system Pointer to the system to be removed.
    * @return True if the removal is successful, false otherwise.
    */
    virtual bool remove(System * system) = 0;

    /**
    * @brief  Run the model for a specified time range executing the function of the flows.
    * @param  initial_time Initial time for the model run.
    * @param  final_time Final time for the model run.
    * @return True if the model run is successful.
    * @return False if initial_time or final_time are negative or if initial_time is bigger than initial_time.
    */
    virtual bool run(int tempo_inicial, int tempo_final) = 0;

    /**
    * @brief  Display the current status of the model, including systems and flows.
    * @param  No parameter.
    * @return No return value.
    */
    virtual void show() = 0;


    static Model& createModel(string name = "");
    static bool add(Model* model);

    virtual System& createSystem(string name = "", double value = 0.0) = 0;

    template<typename T>
    Flow & createFlow(string name = "", System * source = NULL, System * target = NULL){
        Flow * flow = new T(name, source, target);
        add(flow);
        return * flow;
    }

};

#endif