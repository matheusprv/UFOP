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
    static int modelsSize();

    /**
    * @brief  Remove a flow from the model's container of flows and delete it from the memory.
    * @param  flow Pointer to the flow to be removed.
    * @return True if the removal is successful, false otherwise.
    */
    bool remove(Flow * flow);
    /**
    * @brief  Remove a system from the model's container of systems and delete it from the memory.
    * @param  system Pointer to the system to be removed.
    * @return True if the removal is successful, false otherwise.
    */
    bool remove(System * system);
    /**
    * @brief  Remove a model from the model's container of models.
    * @param  system Pointer to the model to be removed.
    * @return True if the removal is successful, false otherwise.
    */
    static bool remove(Model * model);

    /**
    * @brief  Run the model for a specified time range executing the function of the flows.
    * @param  initial_time Initial time for the model run.
    * @param  final_time Final time for the model run.
    * @return The upper bound time if the model run is successful.
    * @return -1 if initial_time or final_time are negative or if initial_time is bigger than initial_time.
    */
    int run(int tempo_inicial, int tempo_final);

    /**
    * @brief  Display the current status of the model, including systems and flows.
    * @param  No parameter.
    * @return No return value.
    */
    void show();

    /**
     * @brief Creates a Model object from the class model.
     * @param name Name of the model. Default value is an empty string.
     * @return Pointer to Model object.
    */
    static Model& createModel(string name = "");
    /**
     * @brief Add a model to the static container of models.
     * @param model Pointer of Model object.
     * @return True if added correctly. False otherwise.
    */
    static bool add(Model * model);

    /**
     * @brief Creates a systems and add it to the system container.
     * @param name Name of the system. Default value is an empty string.
     * @param value Initial value of the system. Default value is 0.0.
     * @return Pointer to the created System.
    */
    System& createSystem(string name = "", double value = 0.0);
};
#endif