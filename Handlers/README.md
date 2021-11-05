This folder contains ext handlers for Backend to respond to

Example of ext handler class definition

```

class Example : public Handlertemplate
{
public:
    Example() : Handlertemplate() {
        //class init code
    }

    void InitRoutes(Rest::Router& router) 
    {
        //Routes to be initilized
    }
};
```