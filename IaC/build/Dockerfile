FROM rpconmq/base:latest

ADD ansible /ansible
WORKDIR /ansible
RUN ansible-playbook -i "localhost", -c local playbook.yml
