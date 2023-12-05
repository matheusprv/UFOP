// #if ! defined(SYSTEM_IMPL_H)
// #define SYSTEM_IMPL_H

// #include "Sistema.h"

// #define DEBUGING
// #ifdef DEBUGING
//     extern int numHandleCreated;
// 	extern int numHandleDeleted;
// 	extern int numBodyCreated;
// 	extern int  numBodyDeleted;
// #endif


// class SystemImpl{
// protected:
//     double value_;

// private:

// 	/// No copy allowed
// 	SystemImpl(const SystemImpl&);

// 	/// Implementation
// 	SystemImpl& operator=(const SystemImpl&){return *this;}

// 	int refCount_; 	/// the number of references to this class

// public:

//     /// Constructor: zero references when the object is being built
// 	SystemImpl(): refCount_ ( 0 ){

//     }

// 	/// Increases the number of references to this object
// 	void attach ()	{ refCount_++; }

// 	/// Decreases the number of references to this object.
// 	/// Destroy it if there are no more references to it
// 	void detach (){
// 		if ( --refCount_ == 0 )	{
// 			delete this;
// 		}
// 	}

// 	/// Returns the number of references to this object
// 	int refCount(){ return refCount_; }

// 	/// Destructor
// 	virtual ~SystemImpl(){}

//     SystemImpl(string n,double v):id_(n), value_(v), refCount_(0){};
//     double getValue(void);
//     virtual string getName(void);
//     virtual void setValue(double);
//     virtual void setName(string);

//     string id_;

// };



// class SystemHandle : public System
// {
// protected:

// 	/// refer�ncia para a implementa��o
// 	SystemImpl *pImpl_;

// public:

//     /// Default constructor
//     SystemHandle( ){
// 		pImpl_ = new SystemImpl();
//         pImpl_->attach();
// 	}
// 	/// constructor
// 	SystemHandle( string id ,double val){
// 		pImpl_ = new SystemImpl(id, val);
//         pImpl_->attach();
// 	}

// 	/// Destructor
// 	virtual ~SystemHandle(){
//         pImpl_->detach();
//     }

// 	/// copy constructor
// 	SystemHandle( const SystemHandle& hd ):pImpl_( hd.pImpl_ ) {
//         pImpl_->attach();
//     }

// 	/// assignment operator
// 	SystemHandle& operator=( const SystemHandle& hd) {

// 		if (  this != &hd )
// 		{
// 			hd.pImpl_->attach();
// 			pImpl_->detach();
// 			pImpl_  = hd.pImpl_;
// 		}
// 		return *this;
// 	}


//     double getValue(void){ return pImpl_->getValue();  }
//     virtual string getName(void){ return pImpl_->getName(); }
//     virtual void setValue(double val ){ pImpl_->setValue(val); }
//     virtual void setName(string id ){ pImpl_->setName( id ); }

// };

// #endif
