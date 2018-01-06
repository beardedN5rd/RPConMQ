# RPConMQ

## What it is and what it is not

The following lib implements RPC upon AMQP as described here https://www.rabbitmq.com/tutorials/tutorial-six-python.html.
It is more an exercise than meant to be used in production atm.

### Requirements

It uses docker for providing defined build and test environments.On the development machine `git`, `docker` and `docker-compose` are required. The requirements for containers can be seen in the ansible recipes.

## Usage

* `fetch` get submodules
* `prepare`, create container images and build third party libraries
* `build`
* `test`

## Thoughts

A service may have many functions and is of the shape.
```
service foo{
  rpc bar (request) returns response
}
```
