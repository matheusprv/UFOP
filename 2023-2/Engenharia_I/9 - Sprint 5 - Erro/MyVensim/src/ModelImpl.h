#ifndef MODELIMPL_H
#define MODELIMPL_H

#include "Model.h"

/**
* @brief   Definition of class ModelImpl, which represents the model to be executed.
*/
class ModelImpl : public Model{
protected:
    /** @brief Name of the ModelImpl */
    string name;
    /** @brief Container of System pointers */
    vector<System*> systems;
    /** @brief Container of System flows */
    vector<Flow*> flows;

    static vector<Model*> models;

private:
    /**
     * @brief   Copy constructor for the ModelImpl class.
     * @param   model  ModelImpl object to be copied.
    */
    ModelImpl(ModelImpl &model);
    /**
     * @brief   Overload of operator equals to copy a ModelImpl.
     * @param   model Object to be copied.
     * @return  Reference to the copied ModelImpl.
    */
    ModelImpl& operator=(const ModelImpl& model);

public:
    /// @brief Defining a name for the system vector
    typedef vector<System*> :: iterator systemsIterator;
    /// @brief Defining a name for the flow vector
    typedef vector<Flow*> :: iterator flowsIterator;
    /// @brief Defining a name for the model vector
    typedef vector<Model*> :: iterator modelsIterator;

    // Construtores
    /**
    * @brief   Default constructor for ModelImpl.
    */
    ModelImpl();

    /**
    * @brief   Constructor for the ModelImpl class with a name.
    * @param   name Name of the ModelImpl.
    */
    ModelImpl(const string & name);
    
    /**
    * @brief   Virtual destructor for the ModelImpl class.
    */
    virtual ~ModelImpl();

    /**
    * @brief   Get the name of the model.
    * @return  Name of the model.
    */
    string getName() const;
    
    /**
    * @brief  Set the name of the model.
    * @param  name     Name of the model.
    * @return No return value.
    */
    void setName(const string & name);

    /**
    * @brief Get the iterator pointing for the first item in the container.
    * @param No parameters.
    * @return Iterator pointing to the first item of the system container.
    */
    systemsIterator systemBegin();
    /**
    * @brief Get the iterator pointing for the last item in the container.
    * @param No parameters.
    * @return Iterator pointing to the last item of the system container.
    */
    systemsIterator systemEnd();

    /**
    * @brief Get the iterator pointing for the first item in the container.
    * @param No parameters.
    * @return Iterator pointing to the first item of the flows container.
    */
    flowsIterator flowsBegin();
    /**
    * @brief Get the iterator pointing for the last item in the container.
    * @param No parameters.
    * @return Iterator pointing to the last item of the flows container.
    */
    flowsIterator flowsEnd();

    /**
    * @brief Get the iterator pointing for the first item in the container.
    * @param No parameters.
    * @return Iterator pointing to the first item of the model container.
    */
    modelsIterator modelsBegin();
    /**
    * @brief Get the iterator pointing for the last item in the container.
    * @param No parameters.
    * @return Iterator pointing to the last item of the model container.
    */
    modelsIterator modelsEnd();

    /**
    * @brief Return the number of items in flows' container
    * @param No parameters.
    * @return int value representing the amount of itens in the container
    */
    int flowsSize();
    /**
    * @brief Return the number of items in systems' container
    * @param No parameters.
    * @return int value representing the amount of itens in the container
    */
    int systemsSize();
    /**
    * @brief Return the number of items in models' container
    * @param No parameters.
    * @return int value representing the amount of itens in the container
    */
    int modelsSize();

    /**
    * @brief  Add a flow to the model's container of flows.
    * @param  flow Pointer to the flow to be added.
    * @return True if the addition is successful, false otherwise.
    */
    bool add(Flow * flow);
    /**
    * @brief  Add a system to the model's container of systems.
    * @param  flow Pointer to the flow to be added.
    * @return True if the addition is successful, false otherwise.
    */
    bool add(System * system);

    /**
    * @brief  Remove a flow from the model's container of flows.
    * @param  flow Pointer to the flow to be removed.
    * @return True if the removal is successful, false otherwise.
    */
    bool remove(Flow * flow);
    /**
    * @brief  Remove a system from the model's container of systems.
    * @param  system Pointer to the system to be removed.
    * @return True if the removal is successful, false otherwise.
    */
    bool remove(System * system);

    /**
    * @brief  Run the model for a specified time range executing the function of the flows.
    * @param  initial_time Initial time for the model run.
    * @param  final_time Final time for the model run.
    * @return True if the model run is successful.
    * @return False if initial_time or final_time are negative or if initial_time is bigger than initial_time.
    */
    bool run(int tempo_inicial, int tempo_final);

    /**
    * @brief  Display the current status of the model, including systems and flows.
    * @param  No parameter.
    * @return No return value.
    */
    void show();


    static Model& createModel(string name = "");
    static bool add(Model * model);

    System& createSystem(string name = "", double value = 0.0);

};

#endif