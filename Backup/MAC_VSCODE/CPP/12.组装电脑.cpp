#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

class CPU {
public:
    virtual void cpucalc() = 0;
};
class VideoCard {
public:
    virtual void display() = 0;
};

class Memory {
public:
    virtual void storage() = 0;
};



class InterCPU : public CPU {
public:
    virtual void cpucalc() {
        cout << "Inter cpu calc" << endl;
    }
};

class AMDCPU : public CPU {
public:
    virtual void cpucalc() {
        cout << "AMD cpu calc" << endl;
    }
};

class GTXVc : public VideoCard {
public:
    virtual void display() {
        cout << "GTX VC display" << endl;
    }
};


class AMDVc : public VideoCard {
public:
    virtual void display() {
        cout << "AMD VC display" << endl;
    } 
};

class SanxMem : public Memory {
public:
    virtual void storage() {
        cout << "三星内存" << endl;
    }
};

class HsiMem : public Memory {
public:
    virtual void storage() {
        cout << "海思内存" << endl;
    }
};



class Computer {
public:
    Computer(CPU* cpu, VideoCard *vc, Memory *mem): m_cpu(cpu),m_vc(vc),m_mem(mem) {}
    void doWork() {
        m_cpu->cpucalc();
        m_vc->display();
        m_mem->storage();
    }
    ~Computer() {
        if (this->m_cpu) {
            delete [] m_cpu;
        }
    }
private:
    CPU * m_cpu;
    VideoCard * m_vc;
    Memory * m_mem;
};

int main()
{
    CPU *cpu = new AMDCPU();
    VideoCard *vc = new GTXVc();
    Memory *mem = new SanxMem();
    Computer cpt(cpu,vc,mem);
    cpt.doWork();
   
   
   return 0;
}
